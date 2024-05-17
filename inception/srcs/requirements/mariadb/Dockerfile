FROM debian:bullseye

RUN apt-get update -y && \
    apt-get upgrade -y && \
    apt-get -y install mariadb-server 
# RUN : docker 이미지가 빌드될 때 실행
COPY ./conf/my.cnf   /etc/mysql/my.cnf
# ./conf/my.cnf(local에 있는 파일)을 컨테이너 안의 /etc/mysql/my.cnf와 교체
COPY ./tools/mariadbsetup.sh    /mariadbsetup.sh
# 마찬가지로 쉘 스크립트를 컨테이너로 옮김


ENTRYPOINT ["sh", "./mariadbsetup.sh"]
#ENTRYPOINT는 docker 컨테이너가 실행될 때 명령어를 실행(이 경우 환경설정 쉘 스크립트를 실행)
#보통 ENTRYPOINT는 컨테이너의 주요 실행파일 또는 명령어를 정의하는데 사용
#CMD는 실행파일이나 명령어와 함꼐 실행될 기본 인자를 정의하는데 사용
EXPOSE 3306