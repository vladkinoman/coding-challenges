export const isPangram = (s_input) => {
  // This is optional, but it skips unnecessary operations below.
  if (s_input === '') return false;
  
  // Filling up the Map (kv pair of [Number (alpha code) => Number (appearances)])
  let m_alphabet = new Map();
  const code_of_a = 'a'.charCodeAt(0);
  const chars_in_alphabet = 26;
  for (let i = 0; i < chars_in_alphabet; i++) {
    m_alphabet.set(code_of_a + i, 0);
  }
  
  // Iterating the input string and marking the appearances 
  let s = new String(s_input.toLowerCase());
  for (const s_char of s) {
    const code = s_char.charCodeAt(0);
    if (code < code_of_a || code > code_of_a + chars_in_alphabet - 1) continue;
    m_alphabet.set(code, 1);
  }

  // Checking map's values for zeroes (there was no appearance)
  for (const val of m_alphabet.values()) {
    if (val === 0) return false;
  }

  return true;
};
