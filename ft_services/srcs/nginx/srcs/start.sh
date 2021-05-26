#!/bin/sh

echo "telegraf start"
telegraf &

echo "openrc default"
openrc default
sleep 5
echo "openrc boot"
openrc boot
sleep 5
echo "nginx start"
rc-service nginx start
sleep 5

while sleep 1; do
  ps aux |grep nginx |grep -q -v grep
  PROCESS_1_STATUS=$?
  # If the greps above find anything, they exit with 0 status
  # If they are not both 0, then something is wrong
  if [ $PROCESS_1_STATUS -ne 0 ]; then
    echo "One of the processes has already exited."
    exit 1
  fi
done