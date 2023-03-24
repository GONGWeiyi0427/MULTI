
if [ "$USER" = "gong" ] 
    then
        PWD=$(pwd)
        
            source /users/outil/soc/env_soclib.sh
            ssh berlioz "cd $PWD && echo $PWD && source /users/outil/soc/env_soclib.sh && /users/outil/soc/soclib/utils/bin/soclib-cc -p tp6.desc -t systemc_21 -o simul.x && exit "

            source /users/outil/soc/env_soclib.sh
fi