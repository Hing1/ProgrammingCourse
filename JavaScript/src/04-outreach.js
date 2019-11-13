function getDate() {
	var now=new Date();
	var year=now.getYear() + 1900;
	var month=now.getMonth() + 1;
	var date=now.getDate();

	var day=now.getDay();
	var arr_week=new Array("Sunday", "Monday", "Thesday", "Wednesday", "Thursday", "Friday", "Saturday");
	var week=arr_week[day];

	var time="The date is " + year + "-" + month + "-" + date + " " + week + "\n";
	alert(time);
}