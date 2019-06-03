import random 

listOptions = ["Rock","Paper","Scissors"]
print("Winning Rules of the Rock Paper Scissors game as follows:")
print("Rock vs Paper->paper wins")
print("Rock vs Scissors->Rock wins")
print("Paper vs Scissors->Scissors wins \n") 

while True: 
	print("Enter userChoice \n 1. Rock \n 2. Paper \n 3. Scissors \n") 
	
	# take the input from user 
	userChoice = int(input("User turn: ")) 

	# looping until user enter invalid input 
	while userChoice > 3 or userChoice < 1: 
		userChoice = int(input("Enter valid input: ")) 
	
	userChoice = userChoice - 1

	print("User choice is: " + listOptions[userChoice]) 
	print("\nNow its computer turn.......") 

	compChoice = random.randint(0, 2) 
		
	print("Computer choice is: " + listOptions[compChoice]) 

	print(listOptions[userChoice] + " V/s " + listOptions[compChoice]) 

	# Draw 
	if userChoice == compChoice:
		print("---------------------- Draw ----------------------")
		print("Do you want to play again? (Y/N)") 
		ans = input() 

		if ans == 'n' or ans == 'N': 
			break
		continue

	# Win 
	if((userChoice == 0 and compChoice == 1) or
	(userChoice == 1 and compChoice == 0)): 
		print("Paper wins") 
		result = "paper"
	elif((userChoice == 0 and compChoice == 2) or
		(userChoice == 2 and compChoice == 0)): 
		print("Rock wins") 
		result = "Rock"
	elif((userChoice == 1 and compChoice == 2) or
		(userChoice == 2 and compChoice == 1)): 
		print("Scissors win") 
		result = "Scissors"

	if result == listOptions[userChoice]: 
		print("---------------------- User Wins ----------------------") 
	else: 
		print("---------------------- Computer wins ----------------------") 

	print("Do you want to play again? (Y/N)") 
	ans = input() 

	if ans == 'n' or ans == 'N': 
		break

print("\nThanks for playing") 
input("Press any key to exit")