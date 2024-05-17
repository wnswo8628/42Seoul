#!/bin/sh

set -e

chown -R www-data:www-data /var/www/html

#wp-config.php파일 및 wordpress 초기 셋팅
if [ ! -f /var/www/html/index.php ]; then #index.php 가장 기본이 되는 페이지의 php파일
    wp core download --locale=en_US --allow-root #wp-cli 참고
    wp config create --dbname=$MYSQL_DATABASE --dbuser=$MYSQL_USER --dbpass=$MYSQL_PASSWORD --dbhost=mariadb --allow-root
    wp core install --url=https://jugwak.42.fr --admin_user=$WP_ADMIN_NAME --admin_password=$WP_ADMIN_PASSWORD --admin_email=$WP_ADMIN_EMAIL --skip-email --title=$WP_TITLE --allow-root
    wp user create $WP_USER_NAME $WP_USER_EMAIL --user_pass=$WP_USER_PASSWORD --allow-root
fi

exec "php-fpm7.4" "-F" #php-fpm을 포그라운드에서 실행하는 명령어
#동적인 컨텐츠를 생성하고 싶을 때에는 보통 포그라운드로 실행해야합니다.
#포그라운드로 실행하면 실시간 로그 및 출력확인이 가능합니다.