FROM alpine:3.13

RUN 	apk update
RUN		apk add nginx tar

RUN adduser -D -g 'www' www

RUN mkdir /www
RUN chown -R www:www /var/lib/nginx
RUN chown -R www:www /www
RUN mkdir -p /run/nginx
RUN mkdir -p /run/php

COPY srcs/nginx.conf /etc/nginx/nginx.conf

RUN		apk add --no-cache curl php7-common php7-session php7-iconv php7-json php7-gd\
		php7-curl php7-xml php7-mysqli php7-imap php7-cgi fcgi php7-pdo\
		php7-pdo_mysql php7-soap php7-xmlrpc php7-posix php7-mcrypt\
		php7-gettext php7-ldap php7-ctype php7-dom php7

RUN apk update && apk add wget
RUN apk add php7-common php7-session php7-iconv php7-json php7-gd php7-curl php7-xml php7-mysqli php7-imap php7-cgi fcgi php7-pdo php7-pdo_mysql php7-soap php7-xmlrpc php7-posix php7-mcrypt php7-gettext php7-ldap php7-ctype php7-dom
RUN apk add telegraf --repository http://dl-3.alpinelinux.org/alpine/edge/testing/ --allow-untrusted --no-cache
RUN apk add nginx
RUN apk add openssl openrc

RUN apk add --no-cache bash less vim nginx ca-certificates git tzdata zip \
    libmcrypt-dev zlib-dev gmp-dev \
    freetype-dev libjpeg-turbo-dev libpng-dev \
    php7-fpm php7-zlib php7-xmlwriter php7-simplexml php7-phar php7-openssl \
    php7-gmp php7-zip \
    php7-opcache php7-apcu \
    php7-intl php7-bcmath php7-mbstring php7-xmlreader mysql-client && apk add -u musl && \
    rm -rf /var/cache/apk/*

RUN 	mkdir -p /usr/share/webapps/
WORKDIR	/usr/share/webapps/

RUN		curl -LO http://files.directadmin.com/services/all/phpMyAdmin/phpMyAdmin-5.0.2-all-languages.tar.gz -o phpMyAdmin-5.0.2-all-languages.tar.gz
RUN		tar xvf phpMyAdmin-5.0.2-all-languages.tar.gz
RUN		rm phpMyAdmin-5.0.2-all-languages.tar.gz 
RUN		mv phpMyAdmin-5.0.2-all-languages phpmyadmin

COPY	srcs/config.inc.php /usr/share/webapps/phpmyadmin/config.inc.php

RUN     mkdir -p /usr/share/webapps/phpmyadmin/tmp
RUN		chmod -R 755 /usr/share/webapps/
RUN		ln -s /usr/share/webapps/phpmyadmin/ /var/www/localhost/htdocs/phpmyadmin

RUN 	mkdir -p /etc/nginx/snippets
COPY	srcs/fastcgi-php.conf /etc/nginx/snippets/

WORKDIR	/

RUN		apk add telegraf --repository http://dl-3.alpinelinux.org/alpine/edge/testing/ --allow-untrusted --no-cache
COPY	./srcs/telegraf.conf /etc/telegraf/telegraf.conf


COPY srcs/nginx.conf /etc/nginx/nginx.conf
RUN yes "" | openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt

COPY srcs/start.sh ./start.sh
RUN chmod +x /start.sh

EXPOSE 5000

CMD sh ./start.sh	
