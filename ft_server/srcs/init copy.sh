# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    init.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/24 16:59:17 by vbuonvin          #+#    #+#              #
#    Updated: 2021/02/24 16:59:23 by vbuonvin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

service nginx start
service mysql start
service php7.3-fpm start

# Configure a wordpress database
echo "CREATE DATABASE wordpress;" | mysql -uroot
echo "CREATE USER 'vbuonvin'@'localhost' IDENTIFIED BY 'cammello';" | mysql -uroot
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'vbuonvin'@'localhost' WITH GRANT OPTION;"| mysql -uroot
echo "FLUSH PRIVILEGES;"| mysql -uroot
echo "update mysql.user set plugin='' where user='vbuonvin';"| mysql -uroot

bash