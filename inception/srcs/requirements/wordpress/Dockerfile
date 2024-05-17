FROM debian:bullseye

RUN apt-get update -y && \
	apt-get upgrade -y && \
	apt-get -y install mariadb-client wget curl tar php7.4-fpm php-cli php-mysql vim sudo

COPY ./tools/wordpress_setup.sh	/tmp/wordpress_setup.sh
COPY ./conf/www.conf	/etc/php/7.4/fpm/pool.d/www.conf

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
	chmod +x wp-cli.phar && mv wp-cli.phar /usr/bin/wp

WORKDIR /var/www/html
RUN mkdir -p /run/php
#php-fpm가 소켓 파일을 저장할 디렉토리를 생성하는 것입니다.
#처음 실행하면 있을수도 있는데 없을 때 문제가 되므로 명시적으로 넣어주는 것이 좋습니다.

EXPOSE 9000

ENTRYPOINT ["sh", "/tmp/wordpress_setup.sh"]