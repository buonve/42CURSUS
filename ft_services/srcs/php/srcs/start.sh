#!/bin/sh

chmod 777 /usr/share/webapps/phpmyadmin/tmp
telegraf &
# php -S 0.0.0.0:5000 -t /usr/share/webapps/phpmyadmin/

openrc default
openrc boot
rc-service nginx start
rc-service php-fpm7 start

while sleep 1; do
  ps aux |grep nginx |grep -q -v grep
  PROCESS_1_STATUS=$?
  ps aux |grep php-fpm7 |grep -q -v grep
  PROCESS_2_STATUS=$?
  # If the greps above find anything, they exit with 0 status
  # If they are not both 0, then something is wrong
  if [ $PROCESS_1_STATUS -ne 0 -o $PROCESS_2_STATUS -ne 0 ]; then
    echo "One of the processes has already exited."
    exit 1
  fi
done