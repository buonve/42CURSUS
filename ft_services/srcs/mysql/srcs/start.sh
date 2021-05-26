#!/bin/sh

telegraf &

#/usr/bin/mysqld_safe -u root &
#/bin/sleep 5

if ! test -f "/export.sql"; then
    /usr/bin/mysql_install_db --user=root
fi

mv /export_new.sql /var/lib/mysql/export_new.sql

/usr/bin/mysqld_safe --datadir="/var/lib/mysql" &
/bin/sleep 5

if ! test -f "/var/lib/mysql/export.sql"; then
    /bin/echo "CREATE DATABASE wordpress;" | /usr/bin/mysql -uroot
    echo "export.sql NOT exists."
    /bin/echo "CREATE USER 'utente'@'%' IDENTIFIED BY 'paroladordine';" | /usr/bin/mysql -uroot
    /bin/echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'utente'@'%' WITH GRANT OPTION;"| /usr/bin/mysql -uroot
    # comando non eseguibile nelle nuove versioni di MariaDB
    # bin/echo "UPDATE mysql.user set plugin='' where user='root';"| mysql -uroot
    /bin/echo "FLUSH PRIVILEGES;"| /usr/bin/mysql -uroot
    mv /var/lib/mysql/export_new.sql /var/lib/mysql/export.sql
    /usr/bin/mysql -uroot -ppassword -Dwordpress < /var/lib/mysql/export.sql
else
    echo "export.sql DOES exists."
fi

while /usr/bin/mysqladmin ping --silent; do
    /bin/sleep 5
done
