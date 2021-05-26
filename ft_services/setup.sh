#kubectl delete pods,services,deployments --all
#curl -LO https://github.com/kubernetes/minikube/releases/download/v1.19.0/minikube-darwin-amd64
#rm minikube
#mv minikube-darwin-amd64 minikube
#chmod 755 minikube
## ./minikube delete
#./minikube --vm-driver=docker start --extra-config=apiserver.service-node-port-range=1-35000
#eval $(./minikube docker-env)

# minikube addons enable dashboard

kubectl get configmap kube-proxy -n kube-system -o yaml | \
sed -e "s/strictARP: false/strictARP: true/" | \
kubectl apply -f - -n kube-system

kubectl apply -f srcs/metallb/namespace.yaml
kubectl apply -f srcs/metallb/metallb.yaml
kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"

kubectl apply -f srcs/metallb/metallb_config.yaml

docker build -t my_ftps -f ./srcs/ftps/Dockerfile ./srcs/ftps
kubectl apply -f srcs/ftps/ftps_deplo.yaml
kubectl apply -f srcs/ftps/ftps_servi.yaml

docker build -t my_influx -f ./srcs/influxdb/Dockerfile ./srcs/influxdb
kubectl apply -f srcs/influxdb/influx_volume.yaml
kubectl apply -f srcs/influxdb/influx_servi.yaml
kubectl apply -f srcs/influxdb/influx_deplo.yaml

docker build -t my_grafana -f ./srcs/grafana/Dockerfile ./srcs/grafana
kubectl apply -f srcs/grafana/grafana_deplo.yaml
kubectl apply -f srcs/grafana/grafana_servi.yaml

docker build -t my_mysql -f ./srcs/mysql/Dockerfile ./srcs/mysql
kubectl apply -f srcs/mysql/mysql_volume.yaml
kubectl apply -f srcs/mysql/mysql_deplo.yaml
kubectl apply -f srcs/mysql/mysql_servi.yaml

docker build -t my_phpmyadmin -f ./srcs/php/Dockerfile ./srcs/php
kubectl apply -f srcs/php/phpmyadmin_servi.yaml
kubectl apply -f srcs/php/phpmyadmin_deplo.yaml

docker build -t my_wordpress -f ./srcs/wordpress/Dockerfile ./srcs/wordpress
kubectl apply -f srcs/wordpress/wordpress_servi.yaml
kubectl apply -f srcs/wordpress/wordpress_deplo.yaml

kubectl apply -f srcs/dashboard/dashboard_deploy.yaml
kubectl apply -f srcs/dashboard/dashboard_admin.yaml

docker build -t my_nginx -f ./srcs/nginx/Dockerfile ./srcs/nginx
kubectl apply -f srcs/nginx/nginx_deplo.yaml
kubectl apply -f srcs/nginx/nginx_servi.yaml

printf "BEARER TOKEN:\n\n"
kubectl get secret -n kubernetes-dashboard $(kubectl get serviceaccount admin-user -n kubernetes-dashboard -o jsonpath="{.secrets[0].name}") -o jsonpath="{.data.token}" | base64 --decode
printf "\n\nˆˆˆBEARER TOKENˆˆˆ\n\n"

#./minikube dashboard
kubectl proxy &
sleep 10
printf "DASHBOARD URL:\n\nhttp://localhost:8001/api/v1/namespaces/kubernetes-dashboard/services/https:kubernetes-dashboard:/proxy/\n\n"
open http://localhost:8001/api/v1/namespaces/kubernetes-dashboard/services/https:kubernetes-dashboard:/proxy/
