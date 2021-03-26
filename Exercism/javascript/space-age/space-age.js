const YEAR_ON_EARTH_IN_SECONDS = 31557600;

export const age = (s_planet, seconds) => {
  let orbital_period;
  switch (s_planet)
  {
  case 'mercury':
      orbital_period = 0.2408467;
      break;
  case 'venus':
      orbital_period = 0.61519726;
      break;
  case 'mars':
      orbital_period = 1.8808158;
      break;
  case 'jupiter':
      orbital_period = 11.862615;
      break;
  case 'saturn':
      orbital_period = 29.447498;
      break;
  case 'uranus':
      orbital_period = 84.016846;
      break;
  case 'neptune':
      orbital_period = 164.79132;
      break;
  default:
      // earth
      orbital_period = 1.0;
      break;
  }
  return Number.parseFloat( 
    (seconds / (orbital_period * YEAR_ON_EARTH_IN_SECONDS)).toFixed(2));
};
