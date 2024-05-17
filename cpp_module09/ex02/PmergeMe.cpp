/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:41:09 by jugwak            #+#    #+#             */
/*   Updated: 2023/10/13 16:59:29 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe :: PmergeMe()
{
	
}

PmergeMe :: PmergeMe(int ac, char **av)
{
	int i = 1;

	try
	{
		while (i < ac)
		{
			std::string	input(av[i]);
			std::istringstream ss(input);
			std::string temp;
			while (std::getline(ss, temp, ' '))
			{
				if (temp.empty())
					continue ;
				validInput(temp);
			}
			i++;
		}
		int j = 1;

		while (j < ac)
		{
			std::string input2(av[j]);
			std::istringstream ss2(input2);
			std::string tmp;
			while (std::getline(ss2, tmp, ' '))
			{
				if (tmp.empty())
					continue;
				this->input_data.push_back(static_cast<int>(strtod(tmp.c_str(), NULL)));
			}
			j++;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

PmergeMe :: PmergeMe(const PmergeMe &temp)
{
	this->input_data = temp.input_data;
	*this = temp;
}

PmergeMe&	PmergeMe :: operator=(const PmergeMe &temp)
{
	if (this != &temp)
	{
		this->input_data = temp.input_data;
	}
	return (*this);
}

PmergeMe :: ~PmergeMe()
{
	
}

void	PmergeMe :: excute(void)
{
	try
	{
		if (this->input_data.empty())
			throw PmergeMe :: Error();
		printBefore();
		sortVector();
		sortDeque();
	}
	catch(const std::exception& e){
	}
}

void	PmergeMe :: validInput(std::string temp)
{
	char *ptr = NULL;
	double value;

	value = std::strtod(temp.c_str(), &ptr);
	if (value == 0.0 && !std::isdigit(temp[0]))
		throw PmergeMe :: Error();
	if (*ptr && std::strcmp(ptr, "f"))
		throw PmergeMe :: Error();
	if (value < 0)
		throw PmergeMe :: Error();
	if (value != static_cast<int>(value))
		throw PmergeMe :: Error();
}

void	PmergeMe :: printBefore(void)
{
	std::vector<int>::iterator iter;

	std::cout << "Before : ";
	for (iter = this->input_data.begin(); iter != this->input_data.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;
}

void	PmergeMe :: printAfter()
{
	std::vector<int>::iterator iter;

	std::cout << "After : ";
	for (unsigned int i = 0; i < vecPairFirst.size(); i++)
		std::cout << this->vecPairFirst.at(i) << " ";
	std::cout << std::endl;
}

void	PmergeMe :: copyVector(void)
{
	std::vector<int>::iterator iter;

	for (iter = this->input_data.begin(); iter != this->input_data.end(); iter++)
		this->vec_data.push_back(*iter);
}

void	PmergeMe :: copyDeque(void)
{
	std::vector<int>::iterator iter;

	for (iter = this->input_data.begin(); iter != this->input_data.end(); iter++)
		this->deq_data.push_back(*iter);
}

void	PmergeMe :: makeVecPair()
{
	int	size;
	unsigned int i;

	i = 0;
	size = this->vec_data.size() / 2;
	while (size != 0)
	{
		this->vecPair.push_back(std::make_pair(this->vec_data.at(i), this->vec_data.at(i + 1)));
		i += 2;
		size--;
	}
}

void	PmergeMe :: sortVecPair()
{
	unsigned int i;
	int tmp;

	i = 0;
	while (i < this->vecPair.size())
	{
		if (this->vecPair.at(i).first < this->vecPair.at(i).second)
		{
			tmp = this->vecPair.at(i).first;
			this->vecPair.at(i).first = this->vecPair.at(i).second;
			this->vecPair.at(i).second = tmp;
		}
		i++;
	}
}

void	PmergeMe :: divideVecPair(void)
{
	size_t i;

	vecPairFirst.push_back(this->vecPair.at(0).second);

	i = 0;
	while (i < this->vecPair.size())
	{
		vecPairFirst.push_back(this->vecPair.at(i).first);
		vecPairSecond.push_back(this->vecPair.at(i).second);
		i++;
	}
}

int	PmergeMe :: jacobsthal(int index)
{
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	return (jacobsthal(index - 1) + 2 * jacobsthal(index - 2));
}

void	PmergeMe :: vec_generateJacobInsertionSequence()
{
	int size;
	int	jIndex;
	int index;

	size = this->vecPairSecond.size();
	index = 3;

	while ((jIndex = jacobsthal(index)) < size - 1)
	{
		this->jacobSequence.push_back(jIndex);
		index++;
	}
}

void	PmergeMe :: vec_generatePositions()
{
	size_t val;
	size_t pos;
	size_t lastpos;
	size_t i;

	if (this->vecPairSecond.empty())
		return ;
	vec_generateJacobInsertionSequence();
	lastpos = 1;
	val = 1;
	i = 0;
	while (i < this->jacobSequence.size())
	{
		val = this->jacobSequence.at(i);
		this->positions.push_back(val);
		pos = val - 1;
		while (pos > lastpos)
		{
			this->positions.push_back(pos);
			pos--;
		}
		lastpos = val;
		i++;
	}
	while (val++ < this->vecPairSecond.size())
		this->positions.push_back(val);
}

int	PmergeMe :: vec_binarySearch(std::vector<int> array, int target, int begin, int end)
{
	int mid;

	while (begin <= end)
	{
		mid = begin + (end - begin) / 2;
		if (target == array.at(mid))
			return (mid);
		if (target > array.at(mid))
			begin = mid + 1;
		else
			end = mid - 1;
	}
	if (target > array.at(mid))
		return (mid + 1);
	else
		return (mid);
}

void	PmergeMe :: insertToFirstVec()
{
	std::vector<int>::iterator iter;
	int	target;
	size_t	endPos = 0;
	size_t	addedCount;
	size_t pos;

	vec_generatePositions();
	addedCount = 0;

	for (iter = this->positions.begin(); iter < this->positions.end(); iter++)
	{
		target = this->vecPairSecond.at(*iter - 1);

		endPos = *iter + addedCount;
		pos = vec_binarySearch(this->vecPairFirst, target, 0, endPos);
		this->vecPairFirst.insert(this->vecPairFirst.begin() + pos, target);
		addedCount++;
	}
	if (this->vec_data.size() % 2 != 0)
	{
		target = this->vec_data.at(this->vec_data.size() - 1);
		pos = vec_binarySearch(this->vecPairFirst, target, 0, this->vecPairFirst.size() - 1);
		this->vecPairFirst.insert(this->vecPairFirst.begin() + pos, target);
	}
}

void	PmergeMe :: sortVector(void)
{
	copyVector();
	clock_t	startTime = clock();
	if (vec_data.size() == 1)
		this->vecPairFirst.push_back(this->vec_data.front());
	else
	{
		makeVecPair();
		sortVecPair();
		FordMergeVec(this->vecPair, 0, vecPair.size() - 1);
		divideVecPair();
		insertToFirstVec();
	}
	clock_t	endTime = clock();
	printAfter();
	clock_t exTime = endTime - startTime;
	std::cout << "Time to process a range of "
		<< input_data.size() << " elements with std::vector : " << (float)exTime * 1000 / CLOCKS_PER_SEC << " ms" << std::endl;
}

void	PmergeMe :: FordMergeVec(std::vector<std::pair<int, int> > &vecPair, int left, int right)
{
	if (left >= right)
		return ;
	
	int mid = left + (right - left) / 2;
	FordMergeVec(vecPair, left, mid);
	FordMergeVec(vecPair, mid + 1, right);
	mergeVec(vecPair, left, mid, right);
}

void	PmergeMe :: mergeVec(std::vector<std::pair<int, int> > &array, int begin, int mid, int end)
{
	size_t leftArrayIndex;
	size_t rightArrayIndex;
	size_t mergedArrayIndex;

	std::vector<std::pair<int, int> > leftArray(array.begin() + begin, array.begin() + mid + 1);
	std::vector<std::pair<int, int> > rightArray(array.begin() + mid + 1, array.begin() + end + 1);

	leftArrayIndex = 0;
	rightArrayIndex = 0;
	mergedArrayIndex = begin;

	while (leftArrayIndex < leftArray.size() && rightArrayIndex < rightArray.size())
	{
		if (leftArray[leftArrayIndex].first <= rightArray[rightArrayIndex].first)
		{
			array[mergedArrayIndex] = leftArray[leftArrayIndex];
			leftArrayIndex++;
		}
		else
		{
			array[mergedArrayIndex] = rightArray[rightArrayIndex];
			rightArrayIndex++;
		}
		mergedArrayIndex++;
	}
	while (leftArrayIndex < leftArray.size())
	{
		array[mergedArrayIndex] = leftArray[leftArrayIndex];
		leftArrayIndex++;
		mergedArrayIndex++;
	}
	while (rightArrayIndex < rightArray.size())
	{
		array[mergedArrayIndex] = rightArray[rightArrayIndex];
		rightArrayIndex++;
		mergedArrayIndex++;
	}
}

void	PmergeMe :: makeDeqPair()
{
	int	size;
	unsigned int i;

	i = 0;
	size = this->deq_data.size() / 2;
	while (size != 0)
	{
		this->deqPair.push_back(std::make_pair(this->deq_data.at(i), this->deq_data.at(i + 1)));
		i += 2;
		size--;
	}
}

void	PmergeMe :: sortDeqPair()
{
	unsigned int i;
	int tmp;

	i = 0;
	while (i < this->deqPair.size())
	{
		if (this->deqPair.at(i).first < this->deqPair.at(i).second)
		{
			tmp = this->deqPair.at(i).first;
			this->deqPair.at(i).first = this->deqPair.at(i).second;
			this->deqPair.at(i).second = tmp;
		}
		i++;
	}
}

void	PmergeMe :: divideDeqPair()
{
	size_t i;

	deqPairFirst.push_back(this->deqPair.at(0).second);

	i = 0;
	while (i < this->vecPair.size())
	{
		deqPairFirst.push_back(this->deqPair.at(i).first);
		deqPairSecond.push_back(this->deqPair.at(i).second);
		i++;
	}
}

void	PmergeMe :: deq_generateJacobInsertionSequence()
{
	int size;
	int	jIndex;
	int index;

	size = this->deqPairSecond.size();
	index = 3;

	while ((jIndex = jacobsthal(index)) < size - 1)
	{
		this->deq_jacobSequence.push_back(jIndex);
		index++;
	}
}

void	PmergeMe :: deq_generatePositions()
{
	size_t val;
	size_t pos;
	size_t lastpos;
	size_t i;

	if (this->deqPairSecond.empty())
		return ;
	deq_generateJacobInsertionSequence();
	lastpos = 1;
	val = 1;
	i = 0;
	while (i < this->deq_jacobSequence.size())
	{
		val = this->deq_jacobSequence.at(i);
		this->deq_positions.push_back(val);
		pos = val - 1;
		while (pos > lastpos)
		{
			this->deq_positions.push_back(pos);
			pos--;
		}
		lastpos = val;
		i++;
	}
	while (val++ < this->deqPairSecond.size())
		this->deq_positions.push_back(val);
}

int	PmergeMe :: deq_binarySearch(std::deque<int> array, int target, int begin, int end)
{
	int mid;

	while (begin <= end)
	{
		mid = begin + (end - begin) / 2;
		if (target == array.at(mid))
			return (mid);
		if (target > array.at(mid))
			begin = mid + 1;
		else
			end = mid - 1;
	}
	if (target > array.at(mid))
		return (mid + 1);
	else
		return (mid);
}

void	PmergeMe :: insertToFirstDeq()
{
	std::deque<int>::iterator iter;
	int	target;
	size_t	endPos = 0;
	size_t	addedCount;
	size_t pos;

	deq_generatePositions();
	addedCount = 0;

	for (iter = this->deq_positions.begin(); iter < this->deq_positions.end(); iter++)
	{
		target = this->deqPairSecond.at(*iter - 1);

		endPos = *iter + addedCount;
		pos = deq_binarySearch(this->deqPairFirst, target, 0, endPos);
		this->deqPairFirst.insert(this->deqPairFirst.begin() + pos, target);
		addedCount++;
	}
	if (this->deq_data.size() % 2 != 0)
	{
		target = this->deq_data.at(this->deq_data.size() - 1);
		pos = deq_binarySearch(this->deqPairFirst, target, 0, this->deqPairFirst.size() - 1);
		this->deqPairFirst.insert(this->deqPairFirst.begin() + pos, target);
	}
}

void	PmergeMe :: sortDeque(void)
{
	copyDeque();
	clock_t starttime = clock();
	if (deq_data.size() == 1)
		this->deqPairFirst.push_back(this->deq_data.front());
	else
	{
		makeDeqPair();
		sortDeqPair();
		FordMergeDeq(this->deqPair, 0, this->deqPair.size() - 1);
		divideDeqPair();
		insertToFirstDeq();
	}
	clock_t endtime = clock();
	clock_t exTime = endtime - starttime;
	std::cout << "Time to process a range of "
		<< input_data.size() << " elements with std::deque : " << (float)exTime * 1000 / CLOCKS_PER_SEC << " ms" << std::endl;
}

void	PmergeMe :: mergeDeq(std::deque<std::pair<int, int> > &deqPair, int left, int mid, int right)
{
	size_t leftArrayIndex;
	size_t rightArrayIndex;
	size_t mergedArrayIndex;

	std::deque<std::pair<int, int> > leftArray(deqPair.begin() + left, deqPair.begin() + mid + 1);
	std::deque<std::pair<int, int> > rightArray(deqPair.begin() + mid + 1, deqPair.begin() + right + 1);

	leftArrayIndex = 0;
	rightArrayIndex = 0;
	mergedArrayIndex = left;

	while (leftArrayIndex < leftArray.size() && rightArrayIndex < rightArray.size())
	{
		if (leftArray[leftArrayIndex].first <= rightArray[rightArrayIndex].first)
		{
			deqPair[mergedArrayIndex] = leftArray[leftArrayIndex];
			leftArrayIndex++;
		}
		else
		{
			deqPair[mergedArrayIndex] = rightArray[rightArrayIndex];
			rightArrayIndex++;
		}
		mergedArrayIndex++;
	}
	while (leftArrayIndex < leftArray.size())
	{
		deqPair[mergedArrayIndex] = leftArray[leftArrayIndex];
		leftArrayIndex++;
		mergedArrayIndex++;
	}
	while (rightArrayIndex < rightArray.size())
	{
		deqPair[mergedArrayIndex] = rightArray[rightArrayIndex];
		rightArrayIndex++;
		mergedArrayIndex++;
	}
}

void	PmergeMe :: FordMergeDeq(std::deque<std::pair<int, int> > &deqPair, int left, int right)
{
	if (left >= right)
		return ;
	
	int mid = left + (right - left) / 2;
	FordMergeDeq(deqPair, left, mid);
	FordMergeDeq(deqPair, mid + 1, right);
	mergeDeq(deqPair, left, mid, right);
}

const	char * PmergeMe :: Error :: what(void) const throw()
{
	return ("Error");
}