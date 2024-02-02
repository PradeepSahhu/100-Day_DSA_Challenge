#!/opt/homebrew/bin/bash

if [ $#1 -eq 0 ]
then
	
	echo "Please Enter any message"
	exit 1
	
else 
		
	git add .
	wait
	echo "Added to Staging Area"
	git commit -m "$1"
	sleep 1
	echo "Commited with the following message : $1"
	git push -u origin main --force
	sleep 1
	echo "Pused forcefully to the github"
	
fi

echo "The message was : $1"
	



