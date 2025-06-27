#Conectarse al servidor principal
ssh -p 443 192.168.10.1

#Nos debe salir
#   jmayorgab@serversalafis:~$ hostname
#   serversalafis

#Al ejecutar sinfo podemos ver todos los nodos del cluster, sinfo -l nos brinda mas información

Mediante el comando

jmayorgab@serversalafis:~$ srun -p 12threads hostname
sala27.salafis.net

accedemos a la partición

jmayorgab@serversalafis:~$ srun -p 12threads -n 8 hostname
sala27.salafis.net
sala27.salafis.net
sala27.salafis.net
sala27.salafis.net
sala27.salafis.net
sala27.salafis.net
sala27.salafis.net
sala27.salafis.net

