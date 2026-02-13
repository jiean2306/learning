import random

while True: 
	choice = input("Heads or Tails?\n-->")
	result = random.choice(["Heads","Tails"])
	print(f"It was {result}!")
	gameon = input("Continue the program or End the program\nType <anything> to continue||Type 'End' to end the program\n-->")
	if gameon in ["END", "End", "end"]:
		print("The program has ended")
		break
	else: 
		print("Let's " + "continue " + "the program")
