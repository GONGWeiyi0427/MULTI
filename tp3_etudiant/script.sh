

# DIR FILE 
PWD=$(pwd)
source /users/outil/soc/env_soclib.sh

# CHANGE tp1.desc 
ssh berlioz "cd $PWD && echo $PWD && source /users/outil/soc/env_soclib.sh && /users/outil/soc/soclib/utils/bin/soclib-cc -p tp3.desc -t systemc_21 -o simul.x && exit "

source /users/outil/soc/env_soclib.sh

