if [ "$USER" = "gong" ] 
    then
        PWD=/users/enseig/gong/Bureau/tp3_etudiant
        #if [ "$1" = "clean" ]
        #then
        #    rm simul.x
        #    cd soft/ && make clean
        #else
            source /users/outil/soc/env_soclib.sh
            ssh berlioz "cd $PWD && echo $PWD && source /users/outil/soc/env_soclib.sh && /users/outil/soc/soclib/utils/bin/soclib-cc -p tp3.desc -t systemc_21 -o simul.x  && exit "
            #&& cd soft/ && make clean && make
            source /users/outil/soc/env_soclib.sh
fi
#elif [ "$USER" = "" ] 
#    then
#        PWD=/users/enseig/lastra/M1SESI/IOC-FPGA-MULTI/MULTI/TP7/tp7_etudiant
#        if [ "$1" = "clean" ]
#        then
#            rm simul.x
#            cd soft/ && make clean
#        else
#            source /users/outil/soc/env_soclib.sh
#            ssh berlioz "cd $PWD && echo $PWD && source /users/outil/soc/env_soclib.sh && /users/outil/soc/soclib/utils/bin/soclib-cc -p tp7.desc -t systemc_21 -o simul.x &&  make -C soft/ && exit "
#            source /users/outil/soc/env_soclib.sh
#        fi
#fi



