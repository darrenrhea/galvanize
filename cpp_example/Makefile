default: install

install: clean uninstall
	pip install .
	py.test -s

uninstall:
	pip uninstall -y cpp_using_package || printf "Was not already installed\n"

clean:
	rm -rf __pycache__
	rm -rf build
	rm -rf .cache
	rm -rf dist
	rm -rf *.egg-info

autoformat:
	clang-format -i --style google *.cpp

lint:
	flake8 .

