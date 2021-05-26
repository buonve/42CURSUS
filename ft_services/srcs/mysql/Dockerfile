FROM	alpine:3.13

RUN		apk update
RUN		apk add mysql mysql-client --no-cache openrc

RUN		mkdir -p /run/mysqld/
RUN		mkdir -p /run/mysql/
COPY	/srcs/my.cnf /etc/
COPY	/srcs/export.sql /export_new.sql

# inizialmente usavo questi due comandi
RUN 	openrc default
RUN		/etc/init.d/mariadb setup

# TELEGRAF
RUN		apk add telegraf --repository http://dl-3.alpinelinux.org/alpine/edge/testing/ --allow-untrusted --no-cache
COPY	./srcs/telegraf.conf /etc/telegraf/telegraf.conf

# START
EXPOSE 	3306

COPY	srcs/start.sh ./start.sh
RUN		chmod +x /start.sh
CMD		sh -x ./start.sh
