# RoomieStats
## Version 0.2.1
> Version 0.2.1 implements some basic features of the app
- Launcher properly boots application to whatever dr it is stored in
- Application takes inputs and provieds documentation with help command
- Add, Display, BestR commands all terminate the program as they don't have a purpose yet

> Things to add for Version 0.2.2 or 0.3.1 (depending on size of push)
- Actual fucntionality for the Add call.
- Changing and pushing the master.csv file to a seperate repo or server space where the data can remain unchanged and stored until next access
- more documentation as code is cluttered and hard to read

That's all for now,
Jack

## Version 0.2.2
> Added documentation for all functions in all files. Should be easier to understand what the hell I am rambling on about! 

That's all for now,
Jack

## Version 0.2.3
> Bigger day today both for the code and me perosnally... I won't bore you but I had a bit of a run in with BCHydro and a billing issue, I missed a mandatory co-op seminar (my advisor let me off the hook, but still stresfull) and I have two midterms over the next two days. I should probably be studying for those, but this is way more interesting lol. Anyways V0.2.3 mainly includes more functionaly for the program. With the addition of 4 or 5 new fucntions the program now succesfully asks which task youve completed (which corresponds to an int value between 1-5) and how many times you've complete it. If you take a trace through the code you can see how this works, but I am especially proud of the times_checker function which takes a inout of Y or N to make sure you are inouting the data you wanted to. It will give you a second chance if you made a numerical error as well which is very helpful! Below is a list of all the new functions are their inteded purpose:
- duty_checker (takes a input from user and returns a int value that relates to the task you have selected
- duty_define (prompts the user to input what duty they did today and then calls duty_checker to validate that task)
- times_checker (asks the user to confirm if that amount theu inputted is correct)
- times_complete (prompts user to input how many times they have completed a task) 

That's all for now, I hope for a les sexciting day tomorrow,
Jack
