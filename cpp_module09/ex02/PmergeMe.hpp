/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:40:46 by jugwak            #+#    #+#             */
/*   Updated: 2023/10/13 01:02:20 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <vector>
# include <deque>
# include <ctime>
# include <cstring>
# include <cstdlib>

class	PmergeMe
{
	private:
		std::vector<int> input_data;
		std::vector<int> vec_data;
		std::vector<std::pair<int, int> > vecPair;
		std::vector<int> vecPairFirst;
		std::vector<int> vecPairSecond;
		std::vector<int> jacobSequence;
		std::vector<int> positions;

		std::deque<int>	deq_data;
		std::deque<std::pair<int, int> > deqPair;
		std::deque<int> deqPairFirst;
		std::deque<int> deqPairSecond;
		std::deque<int> deq_jacobSequence;
		std::deque<int> deq_positions;
		
		PmergeMe();
	public:
		PmergeMe(int ac, char **av);
		PmergeMe(const PmergeMe &temp);
		PmergeMe& operator=(const PmergeMe &temp);
		~PmergeMe();
		void	validInput(std::string temp);
		void	excute(void);
		
		void	printBefore(void);
		void	printAfter(void);
		
		void	sortVector();
		void	copyVector();
		void	FordMergeVec(std::vector<std::pair<int, int> > &vecPair, int left, int right);
		void	mergeVec(std::vector<std::pair<int, int> > &vecPair, int left, int mid, int right);
		void	makeVecPair();
		void	sortVecPair();
		void	divideVecPair();
		void	insertToFirstVec();
		void	vec_generatePositions();
		void	vec_generateJacobInsertionSequence();
		int		jacobsthal(int index);
		int		vec_binarySearch(std::vector<int> array, int target, int begin, int end);

		void	sortDeque();
		void	copyDeque();
		void	FordMergeDeq(std::deque<std::pair<int, int> > &deqPair, int left, int right);
		void	mergeDeq(std::deque<std::pair<int, int> > &deqPair, int left, int mid, int right);
		void	makeDeqPair();
		void	sortDeqPair();
		void	divideDeqPair();
		void	insertToFirstDeq();
		void	deq_generatePositions();
		void	deq_generateJacobInsertionSequence();
		int		deq_binarySearch(std::deque<int> array, int target, int begin, int end);

		class	Error : public std::exception
		{
			const char * what(void) const throw();
		};
};

#endif