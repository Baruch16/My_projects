import pytest



@pytest.mark.parametrize("test_input, expected_output", [
    ("stone,boy,eleven,jump", "boy, eleven, jump, stone"),
    ("orange,banana,apple,pear","apple, banana, orange, pear"),
])
def test_Print_distinct_words(test_input, expected_output):
    assert Print_distinct_words(test_input) == expected_output


def Print_distinct_words(string:str) ->str:
    """
    Prints a sorted string of unique characters in string form

    Args:
        string(str):The string from which we take the uniques
    Returns:
        string of unique words
    """
    words_list = string.split(",") 
    unique_words = sorted(set(words_list)) 
    return ", ".join(unique_words) 
     