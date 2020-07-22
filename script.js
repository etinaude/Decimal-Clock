function myFunction() {
  return;
}

function main() {
  var d = new Date();
  // standard time
  var S_h = d.getHours();
  var S_m = d.getMinutes();
  var S_s = d.getSeconds();

  // calculate decimal time
  var decimal = S_h * 4166.6666667 + S_m * 69.444444 + S_s * 1.1555555;

  var D_h = Math.floor(decimal / 10000);
  var D_m = Math.floor(decimal / 100).toString();
  if (D_m.length > 2) {
    D_m = D_m.substring(D_m.length - 2, D_m.length);
  }
  var D_s = Math.floor(decimal).toString();
  if (D_s.length > 2) {
    D_s = D_s.substring(D_s.length - 2, D_s.length);
  }

  // formatting
  D_time = D_h + ":" + D_m + ":" + D_s;
  S_time = S_h + ":" + S_m + ":" + S_s;

  // display
  document.getElementById("Decimal").innerHTML = D_time;
  document.getElementById("Standard").innerHTML = S_time;
  document.getElementById("Title").innerHTML = D_time;
}

setInterval(main, 860);
