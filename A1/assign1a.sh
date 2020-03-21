!/bin/bash
clear
echo "-------------------------------------------------------------------------------"
echo "This machine is" $HOSTNAME"."
echo $(last|head -n -2| cut -c1-9 |sort -u| uniq -u |grep -v '^reboot'| wc -l) "users have logged into" $HOSTNAME "since" $(last| tac| head -1 | cut -c13-22)"; they are:"
echo $(last|head -n -2| cut -c1-8|sort -u| uniq -u |grep -v '^reboot'|tr -d '[:blank:]'| tr "\n"  ", "|sed 's/,$//')"."
echo ${HOSTNAME^} "is at IP Address" $(grep $HOSTNAME /etc/hosts | cut -c1-13) "and is running"$(hostnamectl|grep "Operating"| tr ":" " ")"."
echo "You are" $LOGNAME", you have logged in" $(last| grep $LOGNAME | wc -l) "times since" $(last| tac| head -1 | cut -c13-22)"."
echo "-------------------------------------------------------------------------------"
exit 0
