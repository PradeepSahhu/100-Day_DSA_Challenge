#!/opt/homebrew/bin/bash

message=""
counter=-1  # Initialize counter to 1 to avoid issues in the loop condition

if [ $# -eq 0 ]; then
    echo "Please enter any message"
    exit 1
else
    while [ $counter -le $# ]; do
        message="$message $1"  # Concatenate the current argument to the message
        shift  # Move to the next argument
        ((counter++))
    done

    git add .
    wait
    echo "Added to Staging Area"

    git commit -m "$message"
    sleep 1
    echo "Committed with the following message: $message"

    git push -u origin main --force
    sleep 1
    echo "Pushed forcefully to GitHub"
fi

echo "The message was: $message"
