FROM alpine:3.13

RUN apk update
RUN apk add openrc --no-cache
# RUN apk add openssh
RUN apk add openssl
RUN apk add nginx
RUN apk add telegraf --repository http://dl-3.alpinelinux.org/alpine/edge/testing/ --allow-untrusted --no-cache

RUN adduser -D -g 'www' www

RUN mkdir /www
RUN chown -R www:www /var/lib/nginx
RUN chown -R www:www /www
RUN mkdir -p /run/nginx

COPY srcs/nginx.conf /etc/nginx/nginx.conf
COPY srcs/index.html /www/index.html
COPY srcs/script.js /www/script.js

RUN adduser -D user
RUN echo "user:password"|chpasswd
RUN yes "" | openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/certs/localhost.key -out /etc/ssl/certs/localhost.crt

RUN mkdir -p /etc/telegraf
COPY ./srcs/telegraf.conf /etc/telegraf/telegraf.conf
#COPY ./srcs/sshd_config /etc/ssh/sshd_config

COPY srcs/start.sh ./start.sh
RUN chmod +x /start.sh
EXPOSE 80
EXPOSE 443

CMD sh ./start.sh