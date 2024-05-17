FROM debian:bullseye

RUN apt-get -y update; \
    apt-get -y upgrade; \
    apt-get -y install nginx; \
    apt-get -y install openssl;

COPY conf/nginx.conf  /etc/nginx/sites-available/default

RUN openssl req -x509 -nodes \
    -days 365 \
    -newkey rsa:4096 \
    -keyout /etc/ssl/private/jugwak.key \
    -out /etc/ssl/certs/jugwak.crt \
    -subj "/C=KO/ST=Seoul/L=Gaepo/O=42seoul/OU=gon/CN=junjaegwak29@gmail.com"

EXPOSE 443

ENTRYPOINT ["nginx", "-g", "daemon off;"]