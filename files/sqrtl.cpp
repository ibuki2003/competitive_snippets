ll sqrtl(ll n){
  if(n==0)return 0;
  ll x1,x2;
  for(int i=60;i>=0;i--){
    if(n&bit(i)){
      x2=bit(i/2+1);
      break;
    }
  }
  do{
    x1=x2;x2-=(x1*x1-n)/(2*x1);
  }while(x1!=x2);
  if(x2*x2!=n)x2--;
  return x2;
}
