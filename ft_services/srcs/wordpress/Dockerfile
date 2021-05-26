FROM alpine
ARG IP

RUN apk update && apk add wget && mkdir /www 
RUN apk add php7-common php7-session php7-iconv php7-json php7-gd php7-curl php7-xml php7-mysqli php7-imap php7-cgi fcgi php7-pdo php7-pdo_mysql php7-soap php7-xmlrpc php7-posix php7-mcrypt php7-gettext php7-ldap php7-ctype php7-dom
RUN apk add telegraf --repository http://dl-3.alpinelinux.org/alpine/edge/testing/ --allow-untrusted --no-cache
RUN apk add nginx
RUN apk add openssl
RUN apk add openrc

RUN apk add --no-cache bash curl less vim nginx ca-certificates git tzdata zip \
    libmcrypt-dev zlib-dev gmp-dev \
    freetype-dev libjpeg-turbo-dev libpng-dev \
    php7-fpm php7-json php7-zlib php7-xml php7-xmlwriter php7-simplexml php7-pdo php7-phar php7-openssl \
    php7-pdo_mysql php7-mysqli php7-session \
    php7-gd php7-iconv php7-mcrypt php7-gmp php7-zip \
    php7-curl php7-opcache php7-ctype php7-apcu \
    php7-intl php7-bcmath php7-dom php7-mbstring php7-xmlreader mysql-client curl && apk add -u musl && \
    rm -rf /var/cache/apk/*

RUN adduser -D -g 'www' www

RUN chown -R www:www /var/lib/nginx
RUN chown -R www:www /www
RUN mkdir -p /run/nginx

RUN		wget http://wordpress.org/latest.tar.gz && tar -xzvf latest.tar.gz && rm latest.tar.gz
RUN		mv wordpress/* www/
RUN 	mkdir -p /etc/nginx/snippets
COPY	srcs/fastcgi-php.conf /etc/nginx/snippets/

COPY srcs/wp-config.php www/wp-config.php
COPY srcs/nginx.conf /etc/nginx/nginx.conf
RUN yes "" | openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt

RUN mkdir -p /etc/telegraf
COPY srcs/telegraf.conf etc/telegraf/telegraf.conf

EXPOSE 5050

COPY	srcs/start.sh ./start.sh
RUN		chmod +x /start.sh
CMD		sh ./start.sh
