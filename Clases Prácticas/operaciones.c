int suma(int a, int b){
	return (a+b);
}
int resta(int a, int b){
	return (a-b);
}
int producto(int a, int b){
	return (a*b);
}
int divisionEntera(int a, int b){
	return (a/b);
}
int factorial(int a){
	if(a==0)
		return 1;
	else
		return (a*factorial(a-1));
}
