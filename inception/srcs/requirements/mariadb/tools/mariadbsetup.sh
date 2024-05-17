#!/bin/sh

set -e

mkdir -p /var/lib/mysql /var/run/mysqld
chown -R mysql:mysql /var/lib/mysql /var/run/mysqld
chmod 777 /var/run/mysqld

# root유저로 mysql데몬을 실행시킵니다.
mysqld --user=root&

#mysql 실행되는걸 기다립니다.
until mysqladmin ping -hlocalhost -uroot > /dev/null 2>&1; do
    echo "Waiting for MariaDB to start..."
    sleep 1
done

# mariadb의 초기 셋팅을 해주는 명령어 입니다.
mysql -uroot -p${MYSQL_ROOT_PASSWORD} <<EOF
ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
FLUSH PRIVILEGES;
CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';
FLUSH PRIVILEGES;
EOF

#root로 접속한 데몬을 셧다운시킵니다.
mysqladmin -uroot -p${MYSQL_ROOT_PASSWORD} shutdown

# mysql이라는 새로운 유저로 데몬을 실행시킵니다.
exec mysqld --user=mysql