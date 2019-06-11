#!/usr/bin/env python
""" Former Coding interview: Find longest word in dictionary
that is a subsequence of a given string"""

def find_longest_word_in_string(letters, words):
    """Find longest word in dictionary that is a subsequence of a given string"""
    words.sort(key=len, reverse=True)
    for word in words:
        if is_subsequence(letters, word):
            return word

def is_subsequence(text, word):
    """check if word is a substring of text"""
    i = 0
    for char in word:
        i = text.find(char)
        if i == -1:
            return False
        text = text[i+1:]
    return True

if __name__ == '__main__':
    S = "abppplee"
    D = ["able", "ale", "apple", "bale", "kangaroo"]
    print(find_longest_word_in_string(S, D))
