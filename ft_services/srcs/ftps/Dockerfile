FROM alpine:3.13
ARG IP

#VOLUME /sys/fs/cgroup 
RUN apk update
RUN apk add openrc --no-cache
RUN apk add openssl
RUN apk add vsftpd
#RUN rc-update add vsftpd default


RUN apk add telegraf --repository http://dl-3.alpinelinux.org/alpine/edge/testing/ --allow-untrusted --no-cache

RUN adduser -D utente
RUN echo "utente:paroladordine"|chpasswd
RUN yes "" | openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/vsftpd.key -out /etc/ssl/certs/vsftpd.crt

RUN mkdir -p /etc/telegraf
COPY ./srcs/telegraf.conf /etc/telegraf/telegraf.conf
COPY ./srcs/vsftpd.conf /etc/vsftpd/vsftpd.conf

RUN echo ${IP} > ip.txt

COPY srcs/start.sh ./start.sh
RUN chmod +x /start.sh
RUN mkdir /var/upload
RUN chmod 757 -R /var/upload
EXPOSE 21 30021 30020

CMD sh ./start.sh