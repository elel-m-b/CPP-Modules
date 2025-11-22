

#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <ctime>

class Account 
{

    public:

	typedef Account		t;

	static int	getNbAccounts( void );
	static int	getTotalAmount( void );
	static int	getNbDeposits( void );
	static int	getNbWithdrawals( void );
	static void	displayAccountsInfos( void );

	Account( int initial_deposit );
	~Account( void );

	void	makeDeposit( int deposit );
	bool	makeWithdrawal( int withdrawal );
	int		checkAmount( void ) const;
	void	displayStatus( void ) const;


    private:

	static int	_nbAccounts;
	static int	_totalAmount;
	static int	_totalNbDeposits;
	static int	_totalNbWithdrawals;

	static void	_displayTimestamp( void );

	int				_accountIndex;
	int				_amount;
	int				_nbDeposits;
	int				_nbWithdrawals;

	Account( void );

};


int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

// static functions

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}
void	Account::_displayTimestamp( void )
{
    char		buffer[80];
    std::time_t	sec;
    std::tm		*timeinfo;

    std::time(&sec);
    timeinfo = std::localtime(&sec);
    std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", timeinfo);
    std::cout << "[" << buffer << "] ";
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}


// constructor and destructor

Account::Account( int initial_deposit ) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account( void )
{
	_nbAccounts--;
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";amount:" << _amount
				<< ";closed" << std::endl;
}

// member functions

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout	<< ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";p_amount:" << _amount;
	if (withdrawal > _amount)
	{
		std::cout	<< ";withdrawal:refused" << std::endl;
		return (false);
	}
	std::cout	<< ";withdrawal:" << withdrawal;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout	<< ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

int		main( void ) 
{

	typedef std::vector<Account::t>							  accounts_t;
	typedef std::vector<int>								  ints_t;
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;

	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 }; // total mony of every account
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );
	accounts_t				accounts( amounts, amounts + amounts_size );
	accounts_t::iterator	acc_begin	= accounts.begin(); // pointer to first account
	accounts_t::iterator	acc_end		= accounts.end(); // pointer to secend account

	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 }; // (Deposits) of every account chhal dkhel
	size_t const		d_size( sizeof(d) / sizeof(int) );
	ints_t				deposits( d, d + d_size );
	ints_t::iterator	dep_begin	= deposits.begin(); 
	ints_t::iterator	dep_end		= deposits.end();

	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 }; // withdrwals chhal sheb dak khona
	size_t const		w_size( sizeof(w) / sizeof(int) );
	ints_t				withdrawals( w, w + w_size );
	ints_t::iterator	wit_begin	= withdrawals.begin();
	ints_t::iterator	wit_end		= withdrawals.end();

	Account::displayAccountsInfos(); // show the state of all acount before any process 
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, dep_begin );
		  it.first != acc_end && it.second != dep_end;
		  ++(it.first), ++(it.second) ){
		(*(it.first)).makeDeposit( *(it.second) );
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, wit_begin );
		  it.first != acc_end && it.second != wit_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeWithdrawal( *(it.second) );
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	return 0;
}
