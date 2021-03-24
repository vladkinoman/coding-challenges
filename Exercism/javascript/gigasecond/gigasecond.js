const GIGASECOND = 1000000000;

export const gigasecond = (date) => {
  return new Date(Date.parse(date)+GIGASECOND*1000);
};