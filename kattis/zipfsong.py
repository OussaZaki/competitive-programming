"""
Python 2 solution for Zipfsong: https://open.kattis.com/problems/zipfsong 
author - Oussama Zaki <zaki.oussama@gmail.com>
"""
import operator

def stupid_print(s):
    print s

if __name__ == "__main__":
    n, m = map(int, raw_input().split())
    album = dict()
    for i in range(1, n + 1):
        fi, song = raw_input().split()
        album[song] = int(fi) * i
    sorted_album = sorted(album.items(), key=operator.itemgetter(1), reverse=True)[:m]
    map(lambda entry: stupid_print(entry[0]), sorted_album)