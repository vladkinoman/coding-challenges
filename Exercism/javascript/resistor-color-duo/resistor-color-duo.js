export const decodedValue = (decodedValue) => {
  return ("" + COLORS.indexOf(decodedValue[0]) +
   COLORS.indexOf(decodedValue[1])) * 1;
};

export const COLORS = [
  'black',
  'brown',
  'red',
  'orange',
  'yellow',
  'green',
  'blue',
  'violet',
  'grey',
  'white'
];