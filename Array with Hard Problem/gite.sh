#!/opt/homebrew/bin/bash
# // this is just a message

message=""
counter=0

if [ $#1 -eq 0 ]
then
	
	echo "Please Enter any message"
	exit 1
	
else 

	while [ "$#" -ge "$counter" ]; do
		message="$counter"
		((counter++))

	done
	git add .
	wait
	echo "Added to Staging Area"
	git commit -m "$message"
	sleep 1
	echo "Commited with the following message : $1"
	git push -u origin main --force
	sleep 1
	echo "Pused forcefully to the github"
	
fi

echo "The message was : $1"
	



