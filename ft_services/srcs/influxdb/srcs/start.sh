#!/bin/sh

telegraf &
sleep 5 && influx -execute 'CREATE DATABASE metrics' &
influxd