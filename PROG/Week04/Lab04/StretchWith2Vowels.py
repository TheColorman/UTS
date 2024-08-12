import re


def read_sentence() -> list[str]:
    s = input("Sentence: ").lower()
    s = re.sub(r"\s+", " ", s)
    return s.split()


def is_vowel(c: str) -> bool:
    return c in "aeiou"


def count_vowels(segment: str) -> int:
    return sum([is_vowel(c) for c in segment])


def matches(word: str) -> bool:
    segments = word.split("z")
    return any([count_vowels(seg) == 2 for seg in segments])


def count_matches(sentence: list[str]) -> int:
    return sum([matches(word) for word in sentence])


if __name__ == "__main__":
    while True:
        s = read_sentence()
        if "*" in s:
            break
        m = count_matches(s)
        print(f"Matching words = {m}")
    print("Done")
