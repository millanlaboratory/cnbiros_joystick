#/usr/bash
#function usage {
#	echo "usage: $0 RULEID"
#	echo "Possible RULEID: '-encoders' or '-sonars' or '-controller' or '-hokuyo'"
#}
#
#case "$1" in
#	"-encoders")
#		RULENAME="99-usb-serial-encoders.rules"
#		;;
#	"-sonars")
#		RULENAME="99-usb-serial-sonars.rules"
#		;;
#	"-controller")
#		RULENAME="99-usb-serial-controller.rules"
#		;;
#	"-hokuyo")
#		RULENAME="99-usb-serial-hokuyo.rules"
#		;;
#	*)
#		usage;
#		exit 1;
#		;;
#esac

RULENAME="99-usb-joystick.rules"

# Removing current rule
echo "Removing current rule in /etc/udev/$RULENAME"
sudo rm -f /etc/udev/rules.d/$RULENAME

echo "Creating new rule in /etc/udev/$RULENAME"
sudo cp $RULENAME /etc/udev/rules.d/
sudo chmod +x /etc/udev/rules.d/$RULENAME

