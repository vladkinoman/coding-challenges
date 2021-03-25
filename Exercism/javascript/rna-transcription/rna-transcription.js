export const toRna = (sDna) => {
  let n = sDna.length;
  let sRna = new Array(n);
  for (let i = 0; i < n; i++) {
    switch (sDna[i]) {
      case 'G':
        sRna[i] = 'C';
        break;
      case 'C':
        sRna[i] = 'G';
        break;
      case 'T':
        sRna[i] = 'A';
        break;
      case 'A':
        sRna[i] = 'U';
        break;
      default:
        break;
    }
  }
  return sRna.join('');
};
