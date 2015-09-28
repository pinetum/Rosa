 var data = null;
    var graph = null;

    // Called when the Visualization API is loaded.
    function drawVisualization() {
      // Create and populate a data table.
      data = new vis.DataSet();

      // create some nice looking data with sin/cos
      var steps = 500;
      var axisMax = 314;
      var tmax = 4 * 2 * Math.PI;
      var axisStep = axisMax / steps;
      for (var t = 0; t < tmax; t += tmax / steps) {
        var r = 1;
        var x = r * Math.sin(t);
        var y = r * Math.cos(t);
        var z = t / tmax;
        data.add({x:x,y:y,z:z});
      }

      // specify options
      var options = {
        width:  '800px',
        height: '600px',
        style: 'line',
        showPerspective: false,
        showGrid: true,
        keepAspectRatio: true,
        verticalRatio: 1.0
      };

      // create our graph
      var container = document.getElementById('mygraph');
      graph = new vis.Graph3d(container, data, options);

      graph.setCameraPosition(1.0, undefined, undefined);

      graph.redraw();


    }