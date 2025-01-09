#Raheem Shaik
#Hangman FSE

repeat = "y"  # while loop for the entire game
while repeat == "y":

    # Function to find indices of a character in a string:
    import random

    words_to_guess = ["january", "border", "image", "film", "promise", "kids", "lungs", "doll", "rhyme", "damage",
                      "phone", "python", "coding", "loop", "school", "raheem", "pi"]
    word_ay = random.choice(words_to_guess)
    length = len(word_ay)


    def findIndices(string, character):
        indices = []

        for i in range(0, len(string)):
            if string[i] == character:
                indices = indices + [i]

        return indices


    # Function to copy a string into a list:
    def copyStringToList(string, list):
        for i in range(0, len(string)):
            list[i] = string[i]


    # Converts a list of characters to a string:
    def toString(list):
        result = ''
        for i in list:
            result += i

        return result


    # The word to be guessed:

    print("Welcome to hangman!!")
    print()
    print("Let's Start! ¯\(ツ)/¯")
    print()
    word = word_ay
    print("The word has following number of letters: ")
    print(len(word_ay))

    # Maxmimum attempts::
    chances = 10

    # Hangman string:
    hangman = []

    # Fill it with dashes:
    for i in range(0, len(word)):
        hangman = hangman + ['-']

    # Convert string to lower case so we don't have to deal with case mismatches:
    word = word.lower()

    i = 0
    # Loop to loop through each attempt:
    while i < chances:
        # Take the guess:
        print()
        guess = input('Enter a guess (letter or word): ')
        # Convert to lower for the same reason as mentioned before:
        guess = guess.lower()

        # Check if the letter was already guessed. If so, the attempt does not count:
        if (guess in toString(hangman)):
            print()
            print('You already tried this letter, try again.')


        # Check if the guess was a letter:
        elif len(guess) == 1:
            # Check if the letter is in the word:
            if guess in word:
                # If so, replace the dash(es) with the letter in correct positions:
                indices = findIndices(word, guess)
                for index in indices:
                    hangman[index] = guess
            else:
                print()
                print('Wrong guess, try again.')
                i = i + 1
        else:
            # If guess was a word and it matches, copy it into the hangman list:
            if guess == word:
                copyStringToList(guess, hangman)
            else:
                print()
                print('Wrong guess, try again.');
                i = i - 1

        # Show the updated hangman:

        print('Hangman: ' + toString(hangman) + ' (' + str(chances - (i - 1)) + ' attempts left)')

        # Check if the hangman matches the original word:
        if toString(hangman) == word:
            # If so, quit the loop:
            print()
            print('The word was guessed correctly!')
            break;

    print()
    print("(0 attempts left)")
    print()
    print("▁ ▂ ▄ ▅ ▆ ▇ █ ＧＡＭＥ ＯＶＥＲ █ ▇ ▆ ▅ ▄ ▂ ▁")
    print()
    repeat = input("press y to replay the game or x to quit: ")
    if repeat == "x":
        print(".")
        print(".")
        print(".")
        print("Thank you for playing!")