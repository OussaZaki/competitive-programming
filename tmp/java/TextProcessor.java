import java.io.*;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

/**
 * SWERC 2015 - Text Processor
 * Approach: Suffix Tree + Sliding Window. O(|S| + Q)
 * Created by Miguel Araujo on 16-11-2015.
 */

class SuffixTree {
    String s;
    int n;

    ArrayList<Node> t;
    Queue<Integer> q;

    long numSubstrings = 0;
    long numLeaves = 0;

    SuffixTree(String s) {
        this.s = s;
        n = s.length();
        t = new ArrayList<>();
        t.add(new Node(0, 0, -1));
        q = new LinkedList<>();
    }

    class Node {
        int l, r, par, link;
        Map<Character, Integer> next;

        int numChildren = 0;

        Node(int l, int r, int par) {
            this.l = l; this.r = r; this.par = par; this.link = -1;
            next = new HashMap<>();
        }
        int len() {
            return r-l;
        }
        int get(char c) {
            if (!next.containsKey(c))
                next.put(c, -1);
            return next.get(c);
        }
        void set(char c, int val) {
            if (val == -1) {
                if (next.containsKey(c) && next.get(c) != -1)
                    numChildren--;
            } else {
                if (!next.containsKey(c) || next.get(c) == -1)
                    numChildren++;
            }
            next.put(c, val);
        }
    }

    class State {
        int activeNode, activePos;
        State (int activeNode, int activePos) {
            this.activeNode = activeNode; this.activePos = activePos;
        }
    }

    State ptr = new State(0, 0);

    State go(State st, int l, int r) {
        while (l < r) {
            if (st.activePos == t.get(st.activeNode).len()) {
                st = new State(t.get(st.activeNode).get(s.charAt(l)), 0);
                if (st.activeNode == -1) return st;
            }
            else {
                if (s.charAt(t.get(st.activeNode).l + st.activePos) != s.charAt(l))
                    return new State(-1, -1);
                if (r-l < t.get(st.activeNode).len() - st.activePos)
                    return new State(st.activeNode, st.activePos + r-l);
                l += t.get(st.activeNode).len() - st.activePos;
                st.activePos = t.get(st.activeNode).len();
            }
        }
        return st;
    }

    int split(State st) {
        if (st.activePos == t.get(st.activeNode).len())
            return st.activeNode;
        if (st.activePos == 0)
            return t.get(st.activeNode).par;

        Node v = t.get(st.activeNode);
        t.add(new Node(v.l, v.l + st.activePos, v.par));

        t.get(v.par).set(s.charAt(v.l), t.size()-1);
        t.get(t.size()-1).set(s.charAt(v.l + st.activePos), st.activeNode);

        t.get(st.activeNode).par = t.size()-1;
        t.get(st.activeNode).l += st.activePos;
        return t.size()-1;
    }

    int getLink(int v) {
        if (t.get(v).link != -1)
            return t.get(v).link;
        if (t.get(v).par == -1)
            return 0;

        int to = getLink(t.get(v).par);
        t.get(v).link = split(go(new State(to, t.get(to).len()), t.get(v).l + (t.get(v).par == 0 ? 1 : 0), t.get(v).r));
        return t.get(v).link;
    }

    void extend(int pos) {
        while (true) {
            State nptr = go(ptr, pos, pos+1);
            if (nptr.activeNode != -1) {
                ptr = nptr;
                break;
            }

            int mid = split(ptr);

            // adding new Leaf
            numLeaves++;
            q.add(t.size());

            t.add(new Node(pos, n, mid));
            t.get(mid).set(s.charAt(pos), t.size()-1);
            ptr.activeNode = getLink(mid);
            ptr.activePos = t.get(ptr.activeNode).len();
            if (mid == 0) break;
        }
        numSubstrings += numLeaves;
    }

    void reduce(int pos) {
        int leaf = q.poll();
        int parent = t.get(leaf).par;

        while (t.get(leaf).numChildren == 0) {
            if (ptr.activeNode != leaf) { // ok, let's remove this leaf
                numSubstrings -= Math.min(t.get(leaf).r,pos) - t.get(leaf).l;
                t.get(parent).set(s.charAt(t.get(leaf).l), -1);

                leaf = parent;
                parent = t.get(leaf).par;
            }
            else { // can't remove this leaf yet, it's the active node of the current suffix
                if (ptr.activePos == Math.min(t.get(leaf).r, pos) - t.get(leaf).l) break; // activePos is at the end of this leaf, don't split
                int mid = split(ptr);
                ptr.activeNode = mid;
                int l = t.get(leaf).l;

                numSubstrings -= Math.min(t.get(leaf).r, pos) - l;

                t.get(mid).set(s.charAt(l), -1);

                t.set(leaf, t.get(mid));
                t.get(t.get(mid).par).set(s.charAt(t.get(mid).l), leaf);
                t.remove(t.size() - 1);
                break;
            }
        }
        if (t.get(leaf).numChildren != 0)
            numLeaves--;
        else {
            q.add(leaf);
            int to = (t.get(leaf).par == 0) ? 0 : t.get(t.get(leaf).par).link;
            ptr = go(new State(to, t.get(to).len()), t.get(leaf).l + (t.get(leaf).par==0 ? 1 : 0), t.get(leaf).r);
            t.get(leaf).l = pos - t.get(leaf).len();
            t.get(leaf).r = n;
        }
    }

    void debug_printTree(int node) {
        for (Map.Entry<Character, Integer> entry : t.get(node).next.entrySet()) {
            if (entry.getValue() != -1) {
                System.out.println(node + " connected to " + entry.getValue() + " along " + t.get(entry.getValue()).l + " " + t.get(entry.getValue()).r);
                debug_printTree(entry.getValue());
            }
        }
    }
}

public class TextProcessor {
    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader( new InputStreamReader(System.in) );
        String txt = input.readLine();
        String[] split = input.readLine().split(" ");
        int n = Integer.parseInt(split[0]), w = Integer.parseInt(split[1]);

        SuffixTree st = new SuffixTree(txt);
        ArrayList<Long> ans = new ArrayList<>();
        for (int i = 0; i < txt.length(); i++) {
            st.extend(i);
            if (i >= w)
                st.reduce(i + 1);
            ans.add(st.numSubstrings);
        }

        PrintWriter out = new PrintWriter(System.out);
        for (int i = 0; i < n; i++) {
            int k = Integer.parseInt(input.readLine());
            out.println(ans.get(k+w-2));
        }
        out.close();
    }
}
