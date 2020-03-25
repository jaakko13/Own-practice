import random

words = ["apple", "banana", "something", "idk"]

lives = 6
right_count = 0
wrong_count = 0
letter_count = 0
letter = ""
sofar = ""
the_word = list(random.choice(words))
amount = len(the_word)
hidden = []

for char in the_word:
    hidden.append("_ ")


while wrong_count < 6:

    hiddenString = ' '.join(hidden)
    print(f'So far you have: {hiddenString}')


    print("Choose a letter:", end = "")
    letter = input()


    if len(letter) > 1:
        print("Only one letter is allowed.")
        continue
    if not letter.isalpha():
        print("Only letters allowed.")
        continue

    if letter in sofar:
        print("You used that letter already. You have", lives, "lives left.")
        continue
    sofar += letter


    if letter in the_word:
        for i in the_word:
            if i == letter:
                letter_count += 1
        print(letter, "is in the the word", letter_count, "time(s).")
        right_count += letter_count
        letter_count = 0



        for i in range(len(the_word)):
            character = the_word[i]
            if character == letter:
                hidden[i] = the_word[i]
                the_word[i] = "_"

        
        continue



    if letter not in the_word:
        wrong_count += 1
        lives -= 1
        print("Wrong! Try again.", "You have", lives, "lives left.")

    if amount == right_count:
        print("Congratulations! You won. The word was", the_word)

        exit()

print("You lost!")
