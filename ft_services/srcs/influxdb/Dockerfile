FROM alpine:3.13

#VOLUME	/sys/fs/cgroup 
RUN		apk update
RUN		apk add openrc --no-cache
RUN		apk add openssl
RUN		apk add influxdb
RUN		apk add telegraf --repository http://dl-3.alpinelinux.org/alpine/edge/testing/ --allow-untrusted --no-cache

#RUN adduser -D -g 'influxdb' influxdb
RUN		mkdir /influxdb
RUN		chown -R influxdb:influxdb /influxdb
RUN		mkdir -p /run/influxdb

# COPY srcs/nginx.conf /etc/nginx/nginx.conf
RUN		adduser -D utente
RUN		echo "utente:paroladordine"|chpasswd

#RUN ssh-keygen -A
#RUN yes "" | openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/certs/localhost.key -out /etc/ssl/certs/localhost.crt

# RUN mkdir -p /etc/telegraf
COPY	./srcs/telegraf.conf /etc/telegraf/telegraf.conf

COPY	./srcs/start.sh ./start.sh
#RUN chmod +x /start.sh
EXPOSE	8086

CMD		sh ./start.sh