function capitalizeName(name){
  var Str = name.toLowerCase()
  Str = name.split(' ');
  var i = 0;
  for (i = 0; i < Str.length; i++){
      Str[i] = Str[i].charAt(0).toUpperCase() + Str[i].substring(1);
  }
  return Str.join(' ');
}
console.log(capitalizeName("Bryan stevenson"));