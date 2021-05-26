# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/24 16:58:49 by vbuonvin          #+#    #+#              #
#    Updated: 2021/02/24 16:58:52 by vbuonvin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster 

#install os

RUN apt update
RUN apt upgrade -y

#install Nginx

RUN apt install -y wget nginx mariadb-server

#install phpMyAdmin

RUN apt-get -y install php7.3 php-mysql php-fpm php-pdo php-gd php-cli php-mbstring php-gettext
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-english.tar.gz
RUN tar xvf phpMyAdmin-5.0.4-english.tar.gz
RUN mv phpMyAdmin-5.0.4-english /var/www/html/phpmyadmin
RUN rm -rf phpMyAdmin-5.0.4-english.tar.gz


#install wordpress

RUN wget -c https://it.wordpress.org/latest-it_IT.tar.gz -O - | tar -xz -C .
RUN mv wordpress var/www/html/
RUN rm -rf wordpress-5.6.2-it_IT


#copy config file from src

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -subj "/C=GB/ST=Rome/L=Rome/O=Global Security/OU=IT Department/CN=localhost" -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt
COPY ./srcs/wp-config.php var/www/html/wordpress
COPY ./srcs/config.inc.php /var/www/html/phpmyadmin
COPY ./srcs/default /etc/nginx/sites-available
COPY ./srcs/init.sh /
COPY ./srcs/autoindex ./bin
COPY ./srcs/univers/* /var/www/html
RUN chmod 777 ./bin/autoindex
CMD bash init.sh
RUN mkdir /var/www/html/phpmyadmin/tmp/
RUN chmod -R 777 /var/www/html/phpmyadmin/tmp/