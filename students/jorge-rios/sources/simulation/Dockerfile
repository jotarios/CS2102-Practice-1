FROM python:3.7-alpine
RUN apk add --no-cache bash
RUN apk add g++ freetype-dev
RUN pip3 --no-cache-dir install --upgrade pip
RUN pip3 --no-cache-dir install -U setuptools
RUN pip3 --no-cache-dir install matplotlib
WORKDIR /usr/src/app
COPY / ./
ENTRYPOINT ["python", "plotter/plotter.py"]

