using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
// new...
using AutoMapper;
using Assignment_4.Models;

namespace Assignment_4.Controllers
{
    public class Manager
    {
        // Reference to the data context
        private DataContext ds = new DataContext();

        // AutoMapper instance
        public IMapper mapper;

        public Manager()
        {
            // If necessary, add more constructor code here...

            // Configure the AutoMapper components
            var config = new MapperConfiguration(cfg =>
            {
                // Define the mappings below, for example...
                // cfg.CreateMap<SourceType, DestinationType>();
                // cfg.CreateMap<Employee, EmployeeBase>();

                

                cfg.CreateMap<Models.Invoice, Controllers.InvoiceBase>();
                
                cfg.CreateMap<Models.Invoice, Controllers.InvoiceWithDetail>();
                
                cfg.CreateMap<Models.InvoiceLine, Controllers.InvoiceLineBase>();

                cfg.CreateMap<Models.InvoiceLine, Controllers.InvoiceLineWithDetail>();


            });

            mapper = config.CreateMapper();

            // Turn off the Entity Framework (EF) proxy creation features
            // We do NOT want the EF to track changes - we'll do that ourselves
            ds.Configuration.ProxyCreationEnabled = false;

            // Also, turn off lazy loading...
            // We want to retain control over fetching related objects
            ds.Configuration.LazyLoadingEnabled = false;
        }

        // Add methods below
        // Controllers will call these methods
        // Ensure that the methods accept and deliver ONLY view model objects and collections
        // The collection return type is almost always IEnumerable<T>

        // Suggested naming convention: Entity + task/action
        // For example:
        // ProductGetAll()
        // ProductGetById()
        // ProductAdd()
        // ProductEdit()
        // ProductDelete()

        // ############################################################
        // Invoices
        // ############################################################

        public IEnumerable<InvoiceBase> GetAll()
        {
            // The ds object is the data store
            // It has a collection for each entity it manages
            var sort = ds.Invoices.OrderBy(i => i.InvoiceId);
            return mapper.Map<IEnumerable<Invoice>, IEnumerable<InvoiceBase>>(sort);
        }

        /*public InvoiceBase GetOne(int id)
        {
            var o = ds.Invoices.Find(id);
            return (o == null) ? null : Mapper.Map<Invoice, InvoiceBase>(o);
        }*/

        public InvoiceWithDetail InvoiceGetByIdWithDetail(int id)
        {
            var o = ds.Invoices
                .Include("InvoiceLines")
                .Include("InvoiceLines.Track")
                .Include("InvoiceLines.Track.Album")
                .Include("InvoiceLines.Track.MediaType")
                .Include("InvoiceLines.Track.Album.Artist")
                .Include("Customer.Employee")
                .SingleOrDefault(i => i.InvoiceId == id);

            // Return the result, or null if not found
           return (o == null) ? null : mapper.Map<Invoice, InvoiceWithDetail>(o);
        }
        


    }
}