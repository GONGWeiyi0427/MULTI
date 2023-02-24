
if [ "$USER" = "gong" ] 
    then
        PWD=$(pwd)
        
            source /users/outil/soc/env_soclib.sh
            ssh berlioz "cd $PWD  && source /users/outil/soc/env_soclib.sh && /users/outil/soc/soclib/utils/bin/soclib-cc -p tp4.desc -t systemcass -o simul.x  && exit && cd soft/ && make clean && make"
            source /users/outil/soc/env_soclib.sh
fi