import random

possible = ["yes", "definitly", "Without a doubt", "For sure", "Of coures", "no", "Probably not", "maybe", "not sure"]
print("Do you want an answer(yes or no)?")
ans = input()

if ans == "yes":
    print(random.choice(possible))

if ans == "no":
    exit()

