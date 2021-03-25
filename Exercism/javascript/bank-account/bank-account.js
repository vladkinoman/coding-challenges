export class BankAccount {

  constructor() {
    this.is_active = false;
  }

  open() {
    if (this.is_active) {
      throw new ValueError('This accound is already opened.');
    }
    this.is_active = true;
    this.balance_value = 0;
  }

  close() {
    if (!this.is_active) {
      throw new ValueError('This accound is already closed.');
    }
    this.is_active = false;
    this.balance_value = 0;
  }

  deposit(money) {
    if (!this.is_active) {
      throw new ValueError('Open your account before depositing money.');
    }
    if (money < 0) {
      throw new ValueError('Cannot deposit negative amount.');
    }
    this.balance_value += money;
  }

  withdraw(money) {
    if (!this.is_active) {
      throw new ValueError('Open your account before withdrawing money.');
    }
    if (money < 0) {
      throw new ValueError('Cannot withdraw negative amount.');
    }
    if (this.balance_value - money < 0) {
      throw new ValueError('Cannot withdraw more than deposited.');
    }
    this.balance_value -= money;
  }

  get balance() {
    if (!this.is_active) {
      throw new ValueError('This accound is closed.');
    }
    return this.balance_value;
  }
}

export class ValueError extends Error {
  constructor() {
    super('Bank account error');
  }
}