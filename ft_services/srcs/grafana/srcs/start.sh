#!/bin/sh

#/usr/sbin/sshd
telegraf &
cd ./grafana-6.7.2/bin/
./grafana-server
