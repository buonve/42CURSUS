FROM alpine:3.13

RUN apk update
RUN apk add --no-cache --repository=http://dl-cdn.alpinelinux.org/alpine/edge/main libc6-compat
RUN apk add telegraf --repository http://dl-3.alpinelinux.org/alpine/edge/testing/ --allow-untrusted --no-cache

RUN wget https://dl.grafana.com/oss/release/grafana-6.7.2.linux-amd64.tar.gz \
&& tar -zxvf grafana-6.7.2.linux-amd64.tar.gz

RUN mkdir -p /etc/telegraf
COPY ./srcs/telegraf.conf /etc/telegraf/telegraf.conf

COPY srcs/start.sh ./start.sh
RUN mkdir -p /grafana-6.7.2/data
COPY srcs/grafana.db /grafana-6.7.2/data/grafana.db
RUN chmod +x /start.sh
EXPOSE 3000

CMD sh ./start.sh